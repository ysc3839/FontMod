# TGFont
Simple hook to change Telegram desktop's font in Windows.

# Usage
[Download](https://github.com/ysc3839/TGFont/releases) `TGFont.dll` and rename to `winmm.dll`. Then put it in Telegram's path.

# Config file
Create a file with name `TGFont.ini` in Telegram's path.
```
[TGFont]
Find=SimSun
Replace=Microsoft YaHei UI
Size=0
```
`Find`: Font name to find.

`Replace`: Font name to replace.

`Size`: Override all fonts size if this is **NOT ZERO**. Use at your own risk.
