#!/bin/bash -e

# Set up an environment to run tests under Travis CI (see ../.travis.yml)

if [ $# -ne 2 ]; then
  echo "Usage: $0 imp_branch python_version"
  exit 1
fi

cur_dir=$(pwd)
imp_branch=$1
python_version=$2
temp_dir=$(mktemp -d)

# get conda-forge, not main, packages
conda config --remove channels defaults || :
conda config --add channels conda-forge
if [ ${imp_branch} = "develop" ]; then
  IMP_CONDA="imp-nightly"
else
  IMP_CONDA="imp"
fi

cd ${temp_dir}

conda create --yes -q -n python${python_version} -c salilab python=${python_version} ${IMP_CONDA} libboost-devel gxx_linux-64 eigen cereal cmake
eval "$(conda shell.bash hook)"
conda activate python${python_version}

cd ${cur_dir}

rm -rf ${temp_dir}
