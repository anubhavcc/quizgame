TOPDIR := $(shell pwd)
TOPRPMDIR := $(TOPDIR)/build/rpmbuild
all:
	mkdir -p build && cd build && \
	cmake -DCMAKE_BUILD_TYPE=Release .. && make && cd -
install:
	make -C build install
clean:
	rm -rf build
