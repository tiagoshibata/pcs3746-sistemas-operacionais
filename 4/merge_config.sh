#!/bin/sh
#  merge_config.sh - Merges .config and .config-fragment, then runs olddefconfig.
#  Based on scripts/kconfig/merge_config.sh from kernel sources.
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License version 2 as
#  published by the Free Software Foundation.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#  See the GNU General Public License for more details.

set -e

scripts/kconfig/merge_config.sh -m -r .config .config-fragment
CONFIG=$(cat .config)
make ARCH=arm olddefconfig

# Check if requested config was valid
SED_CONFIG_EXP="s/^\(# \)\{0,1\}\(CONFIG_[a-zA-Z0-9_]*\)[= ].*/\2/p"
for CFG in $(echo $CONFIG | sed -n "$SED_CONFIG_EXP") ; do
	REQUESTED_VAL=$(echo CONFIG | grep -w -e "$CFG")
	ACTUAL_VAL=$(grep -w -e "$CFG" .config)
	if [ "x$REQUESTED_VAL" != "x$ACTUAL_VAL" ] ; then
		echo "Value requested for $CFG not in final .config"
		echo "Requested value:  $REQUESTED_VAL"
		echo "Actual value:     $ACTUAL_VAL"
		echo "Aborting"
		exit 1
	fi
done
