## Oat++ Server

This Oat++ server uses multithreading to expose a Discord bot on an API. 

### Build Instructions

1. Add a `.env` file in the root of the `oat-server` project (cmake looks for this when building)
```
# Sample .env
BOT_TOKEN=
```

2. Build and make the server/bot 
```
./build.sh
```

**Note:** The first build may take *quite* some time, such is the disadvantage of submodules as opposed to locally installing the dependent packages.
However, cloning, testing, and managing versions of this project are a bit more maintainable and have less overhead.
Subsequent runs during development shouldn't take as long.