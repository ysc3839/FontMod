# TGFont
Simple hook to change Telegram desktop's font in Windows.

# Usage
Download `TGFont.dll` and rename to `winmm.dll`. Then put it in Telegram's path.

# Config file `TGFont.json`
Config file uses UTF-8 encoding. Supports UTF-8 BOM.
```json
{
    "fonts": [
        {
            "find": "SimSun",
            "replace": "Microsoft YaHei UI",
            "#size": 0
        },
        {
            ...
        }
    ]
}
```
`find`: Font name to find.

`replace`: Font name to replace.

`size`: Override `find` font size, rename/delete this if you don't want to change the font size.

# Thanks
[RapidJSON](http://rapidjson.org/)
