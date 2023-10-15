# Astrid
Jogo 2D baseado em asteroides com uso do mouse

![Logo](assets/2.jpg)

## Como Jogar

- **Movimento:** Através do mouse você poderá controlar a direção que a nave irá atirar.
- **Objetivo:** Defenda a terra das estrelas que vem do espaço.

## Requisitos

Certifique-se de que seu sistema atenda aos seguintes requisitos antes de compilar e executar o jogo:

- [Compilador C++](https://gcc.gnu.org/) instalado
- [CMake](https://cmake.org/) instalado
- [OpenGL](https://www.opengl.org/) instalado
- [GLFW](https://www.glfw.org/) instalado
- [GLM](https://glm.g-truc.net/0.9.9/index.html) instalado

## Instalação dos requisitos no Ubuntu

Para instalar os requisitos no Ubuntu ou derivados, execute o seguinte passo a passo:

1. **Atualize o sistema:**

```bash
sudo apt update
sudo apt upgrade -y
sudo apt dist-upgrade -y
sudo apt autoremove -y
```
2. **Instale o compilador C++:**

```bash
sudo apt install build-essential -y
```
3. **Instale o CMake:**

```bash
sudo apt install cmake -y
```
4. **Instale o OpenGL:**

```bash
sudo apt install libglu1-mesa-dev freeglut3-dev mesa-common-dev -y
```
5. **Instale o GLFW:**

```bash
sudo apt install libglfw3-dev -y
```
6. **Instale o GLM:**

```bash
sudo apt install libglm-dev -y
```



## Compilação com CMake via terminal

Siga estas etapas para compilar o jogo usando o CMake:

1. **Clonar o repositório:**

```bash
git clone https://github.com/FelpLiet/Astrid.git
cd Astrid
```
2. **Crie um diretório de compilação:**

```bash 
mkdir build
cd build
```
3. **Execute o CMake:**
   
```bash
cmake ..
```
**Caso o CMake não encontre o glm, entre no arquivo CMakeLists.txt e altere a linha 25 de:**

```cmake
25| target_link_libraries(ASTRL PUBLIC ${OPENGL_LIBRARIES} glfw GLEW::GLEW glm::glm)
```
**para:**

```cmake
25| target_link_libraries(ASTRL PUBLIC ${OPENGL_LIBRARIES} glfw GLEW::GLEW glm)
```

**Isso aconteceu ao tentar compilar no manjaro, que eh uma distro baseada no arch linux, e o cmake não encontrou o glm, mesmo ele estando instalado.**

4. **Compile o jogo:**

```bash
make
```
5. **Execute o jogo:**

```bash
./Astrid
```
## Compilação com CMake via vscode

**Você também pode compilar utilizando o vscode, para isso, siga os seguintes passos:**

1. **Abra o vscode e instale a extensão CMake Tools.**
2. **Abra o projeto no vscode.**
3. **Clique no icone de ▶ (play) comumente encontrado na barra inferior do vscode.**
4. **Selecione a opção "CMake: Debug" e aguarde a compilação.**

## creditos

<table>
  <tr>
    <td align="center"><a href="https://github.com/ph3523"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/80484091?v=4" width="150px;" alt=""/><br /><sub><b>Pedro Barroso</b></sub></a><br /><a href="mailto:ph.barroso3523@gmail.com" title="Email">📧</a></td>
    <td align="center"><a href="https://github.com/JVictor011"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/91631521?v=4" width="150px;" alt=""/><br /><sub><b>João Victor</b></sub></a><br /><a href="mailto:joaovictor.20739@gmail.com" title="Email">📧</a></td>
    <td align="center"><a href="https://github.com/FelpLiet"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/30266169?v=4" width="150px;" alt=""/><br /><sub><b>Felipe Nogueira</b></sub></a><br /><a href="mailto:felipe.leite23@gmail.com" title="Email">📧</a></td>
  </tr>
</table>

## Contribuição

**Caso encontre algum bug ou tenha alguma sugestão de melhoria, por favor, abra uma issue ou pull request ou entre em contato com um dos contribuidores. Será um prazer ter alguém contribuindo com o projeto.** 
