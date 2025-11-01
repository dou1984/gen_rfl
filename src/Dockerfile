FROM alpine:3.21 AS builder

# RUN sed -i 's/dl-cdn.alpinelinux.org/mirrors.aliyun.com/g' /etc/apk/repositories
# RUN sed -i 's#https://dl-cdn.alpinelinux.org#http://172.22.210.84:10000#g' /etc/apk/repositories

RUN apk update

RUN apk add clang18 clang18-dev clang18-static clang18-libs clang18-libclang clang18-extra-tools clang18-headers g++ gcc python3 libstdc++-dev llvm18-dev llvm18-libs llvm18-static llvm18-linker-tools llvm18-test-utils llvm18-gtest make cmake gtest-dev yaml-cpp-dev gflags-dev libxml2-dev curl-dev autoconf automake libtool m4 llvm18-test-utils llvm18-test-utils-pyc 

RUN ln -s /usr/lib/cmake/clang18 /usr/lib/cmake/clang

WORKDIR /root

RUN wget https://github.com/OlafvdSpek/ctemplate/archive/refs/tags/ctemplate-2.4.tar.gz -O ctemplate-2.4.tar.gz

RUN tar xfz ctemplate-2.4.tar.gz

RUN cd ctemplate-ctemplate-2.4 && ./autogen.sh && ./configure && make -j$(nproc) && make install 

COPY ./ /root/gen_rfl/

WORKDIR /root/gen_rfl/build

RUN cmake -DCMAKE_BUILD_TYPE=Release -DALPINE=ON -DCMAKE_C_COMPILER=clang-18 -DCMAKE_CXX_COMPILER=clang++-18  ..

RUN make -j$(nproc) && make install

FROM alpine:3.21 

# RUN sed -i 's/dl-cdn.alpinelinux.org/mirrors.aliyun.com/g' /etc/apk/repositories
# RUN sed -i 's#https://dl-cdn.alpinelinux.org#http://172.22.210.84:10000#g' /etc/apk/repositories

RUN apk add --no-cache zlib zstd-libs libxml2 yaml-cpp gflags libffi musl-dev libstdc++-dev llvm18-libs

COPY --from=builder /usr/local/bin/gen_rfl /usr/local/bin/gen_rfl

COPY --from=builder /usr/local/include/gen_rfl /usr/local/include/gen_rfl

COPY --from=builder /usr/local/lib/libctemplate.so.3 /usr/local/lib/

WORKDIR /root