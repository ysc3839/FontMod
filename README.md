# TGFont
Simple hook to change Telegram desktop's font in Windows.

# Usage
[Download](https://github.com/ysc3839/TGFont/releases) `TGFont.dll` and rename to `winmm.dll`. Then put it in Telegram's path.

# Config file
Create a file with name `TGFont.json` in Telegram's path. Config file uses UTF-8 encoding. Supports UTF-8 BOM.
```json
{
    "fonts": {
        "SimSun": {
            "replace": "Microsoft YaHei UI",
            "#size": 0
        }
    },
    "debug": false
}
```
key: Font name to find.

`replace`: Font name to replace.

`size`: Override `find` font size, rename/delete this if you don't want to change the font size.

`debug`: Debug mode (will log CreateFont calls into TGFont.log).

# Thanks
[RapidJSON](http://rapidjson.org/)
