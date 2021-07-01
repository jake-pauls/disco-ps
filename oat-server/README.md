## Oat++ Server

This Oat++ server uses multithreading to expose a Discord bot on an API.
For the Discord bot to work, ensure that a `.env` file is located in the root of the `oat-server` project (cmake looks for this on build).

```
# Sample .env
BOT_TOKEN=
```

To install Oat++ as a local dependency (cmake required)

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

*Alternatively, check out this super handy starter [repo](https://github.com/oatpp/oatpp-starter) which has some install scripts*

---

To run the server (oatpp + cmake required):

```
./build.sh
```