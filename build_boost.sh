#!/bin/bash

wget https://boostorg.jfrog.io/artifactory/main/release/1.77.0/source/boost_1_77_0.tar.gz
tar -xvf ./boost_1_77_0.tar.gz;
if [[ $? -gt 0 ]]; then
	exit 1;
fi

pushd boost_1_77_0
	mkdir -p ../boost_build && \
	./bootstrap.sh --prefix=../boost_build && \
	./b2 install
popd
