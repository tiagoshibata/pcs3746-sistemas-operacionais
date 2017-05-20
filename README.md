# Uso:

## Estrutura:

Para não termos de aprender a mexer com Git Submodules, optei por quebrar o linux e a VM para rodá-lo em dois repositórios.

Isso significa que iremos alterar o processo de init nesse repositório e alteraremos o linux [nesse outro](https://github.com/felipegoncalvesmarques/linux).

Para isso, é preciso ter a seguinte estrutura de pasta:

`\folder-qualquer-que-voce-escolher`
  
    `\pcs376-sistemas-operacionais` <- esse repositório
    
    `\linux` <- [repositório do linux](https://github.com/felipegoncalvesmarques/linux)

## Setando ambiente e rodando

Instale o Docker Community Edition:
- [Mac OS X](https://store.docker.com/editions/community/docker-ce-desktop-mac)
- [Windows](https://store.docker.com/editions/community/docker-ce-desktop-windows)
- [Ubuntu](https://store.docker.com/editions/community/docker-ce-server-ubuntu)
- [Outros](https://www.docker.com/community-edition) 

1. Crie uma pasta para clonar os repositórios e rode:

   `git clone https://github.com/felipegoncalvesmarques/linux`

   `git clone https://github.com/felipegoncalvesmarques/pcs3746-sistemas-operacionais.git`

2. Entre na pasta `pcs3746-sistemas-operacionais`

### Se você estiver rodando no Mac OS X ou no Linux, ou possuir um interpretador Bash, você pode usar o run.sh para facilidade o desenvolvimento.

3. Crie o container rodando 

   `docker build -t so ./docker`

4. Rode o container indicando as pastas do linux e do initramfs

   `docker run -v "$PWD/../linux":/home/student/src/linux -v "$PWD":/home/student/src/initramfs so`

## Usando o run.sh

3. Rode `./run.sh -b`

4. Rode `./run.sh`

A saída deve ser:
(To be developed) ...
