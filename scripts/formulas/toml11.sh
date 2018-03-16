#! /bin/bash
#
# toml11
#
# uses CMake

# define the version
VER=5aeb6f24df8785974010a36c63438609cf875f07

# tools for git use
GIT_URL="https://github.com/ToruNiina/toml11.git"
GIT_TAG=$VER

FORMULA_TYPES=("osx" "linux64")

# download the source code and unpack it into LIB_NAME
function download() {
    git clone --depth=1 ${GIT_URL} toml11/
    cd toml11/
    git checkout ${GIT_TAG}
}

# prepare the build environment, executed inside the lib src dir
function prepare() {
  echo "Nothing to prepare."
}

# executed inside the lib src dir
function build() {
  echo "Nothing to build."
}

# executed inside the lib src dir, first arg $1 is the dest libs dir root
function copy() {
    echo `pwd`
    # headers
    if [ -d $1/include ]; then
        rm -rf $1/include/toml11
    fi

    mkdir -p $1/include/toml11
    cp -r * $1/include/toml11

    rm $1/include/toml11/appveyor.yml
    rm $1/include/toml11/PROPOSAL.md
    rm $1/include/toml11/CMakeLists.txt
    rm -rf $1/include/toml11/tests

}

# executed inside the lib src dir
function clean() {
  echo "Nothing to clean."
}
