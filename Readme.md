
# Task
The first task is to write a C++17 routine that computes c as defined below:
c=bpmod m
where b, p, m are positive integers with the following range constraints applied:
b0,109
p0,106
m0,109
The operation defined above is known as modular exponentiation. An example set of operands and the correct result are shown below:
682771105=131999920^234979mod 991540365
The objective is to define a function that can perform modular exponentiation as defined above at compile time, and provide a set of unit tests with a reasonable degree of coverage. The unit tests must also ensure that the computation can be performed at compile time rather than at runtime.

c = b^p mod m

b = 0,10^9    1 000 000 000 
p = 0,10^6    1 000 000
m = 0,10^9    1 000 000 000

# Prerequire
   Docker comatible linux distro. (Ubuntu 20.04 - ok )


## Using docker 

 - install docker from  offical site https://docs.docker.com/engine/install/debian/
 - install docker-compuse tool https://docs.docker.com/compose/install/
 - add your user to docker group (to avoid sudo ): sudo usermod -aG docker $USER

 - choose option - 1)pull ready image or 2)build on your own:

### Option 1) Pull ready image from dockerhub
  run `./docker_pull.sh`

### Option 2) Build image form scratch
  run `./docker_build.sh`

### Start sandbox
  run `./docker_start.sh`



# Build
  `mkdir build`

  `cd build`

  `cmake ../`

  `make`


# Unit test
 - cd build
 - make test

# Accpeture test and Run
    - cd build
    - ./Task1 < ../accepture/input.txt > ../accepture/result.txt


  file ../accepture/input.txt consist input data
    each line is base , exponenta, module 



# IDE vscode support  
   use vscode to open folder

    - install plugins
        "ms-vscode.cpptools"
		    "ms-vscode.cmake-tools"
        "ms-vscode-remote.remote-containers"

    - Ctrl+shift+P
      Remote containers: Rebuild and REopen in Container

    