# TGFont

[简体中文](README.zh_CN.md)
[繁体中文](README.zh_TW.md)

A simple hook tool for changing fonts in Telegram desktop (Windows Version).

>Theoretically, this tool can also support other softwares.

## Usage

1. [Download](https://github.com/ysc3839/TGFont/releases) `TGFont.dll` 
2. rename it to `winmm.dll`.
3. Put it in Telegram's root directory. Then you should be all set.

### Custom Fonts

1. In telegram's root directory, create a sub-directory called ``fonts``, then put your fonts inside the sub-folder.
2. You can enable your fonts directly by editing ``TGFont.json``.

## Configuration

At the first startup after installation. Our config file uses ``UTF-8`` encoding, and ``UTF-8 BOM`` is also supported

### Example

```json
{
    "fonts": {
        "SimSun": {
            "replace": "Microsoft YaHei UI",
            "#size": 0,
            "#width": 0,
            "#weight": 0,
            "#italic": false,
            "#underLine": false,
            "#strikeOut": false
        }
    },
    "debug": false
}
```
`key ("SimSun")`: The font in Telegram you want to replace. (The "Source Font")

`replace`: Your custom font you want to use (The "Target Font").

`size` `width` `weight` `italic` `underLine` `strikeOut`: 5 custom parameters available for fonts.

`debug`: Debug Mode (Will call method ``CreateFont`` and output to TGFont.log).

## Thanks
Thanks to those folks who helped us advertising this repository!

[RapidJSON](http://rapidjson.org/)
