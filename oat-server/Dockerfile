FROM alpine:latest AS cmake-build

# Install deps
RUN apk --no-cache add git linux-headers clang clang-dev gcc g++ make cmake libc-dev ca-certificates openssl-dev openssl-libs-static

# Copy source
WORKDIR /app
ADD . .

# CMake pulls submodules
WORKDIR /app/build 
RUN cmake ..
RUN make

# Run executable
RUN chmod +x ./disco-ps-core
CMD ./disco-ps-core