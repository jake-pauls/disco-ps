## Oat++ Server

To install Oat++ as a local dependency (cmake required)

*Alternatively, check out this super handy starter [repo](https://github.com/oatpp/oatpp-starter) which has some install scripts*

1. Clone from source
```
mkdir tmp && cd tmp
git clone https://github.com/oatpp/oatpp.git
cd oatpp/
```

2. Build with cmake
```
mkdir build && cd build
cmake ..
```

3. Install locally
```
sudo make install
```

To run the server (oatpp + cmake required):

```
./build.sh
```