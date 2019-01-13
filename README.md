# TGFont
[繁体中文](README.zh_TW.md)

修改 Telegram desktop Windows 版字体的简单的 hook 工具. (理论上也支持别的软件)

# 使用方法
[下载](https://github.com/ysc3839/TGFont/releases) `TGFont.dll` 并重命名为 `winmm.dll`. 然后放在 Telegram 的文件夹里.

用户字体: 把字体文件放在 `fonts` 文件夹内, 可以直接使用, 无需安装到系统中.

# 配置文件
初次运行时会创建 `TGFont.json`. 配置文件使用 UTF-8 编码. 支持 UTF-8 BOM.
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
            "#strikeOut": false,
            "#charSet": 0,
            "#outPrecision": 0,
            "#clipPrecision": 0,
            "#quality": 0,
            "#pitchAndFamily": 0
        }
    },
    "debug": false,
    "fixGSOFont": {
            "name": "Microsoft YaHei UI",
            "#size": 0,
            "#width": 0,
            "#weight": 0,
            "#italic": false,
            "#underLine": false,
            "#strikeOut": false,
            "#charSet": 0,
            "#outPrecision": 0,
            "#clipPrecision": 0,
            "#quality": 0,
            "#pitchAndFamily": 0
    }
}
```
`key ("SimSun")`: 要修改的字体名称.

`replace`: 要替换成的字体名称.

`size` `width` `weight` `italic` `underLine` `strikeOut` `charSet` `outPrecision` `clipPrecision` `quality` `pitchAndFamily`: 覆盖原始字体样式. 请参见 [MSDN 文档](https://msdn.microsoft.com/en-us/library/dd145037). 如果不想覆盖的话请把这些项删除或者改名.

`debug`: 调试模式 (会记录 LoadUserFonts 及 CreateFont 调用到 TGFont.log).

`fixGSOFont`: 修复 GetStockObject 字体。若设为 `true` 则会使用 [SystemParametersInfo](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-systemparametersinfow#spi_getnonclientmetrics) 获取系统字体。

> 如果只想替换中文字体，保留英文字体不变，你需要将 "key" 设为中文的 fallback 字体。这个字体在不同语言环境下可能不一样 (比如简体中文是 SimSun)，你需要使用 debug 模式找到对应的字体。

# Thanks
感谢宣传此项目的朋友!

[RapidJSON](http://rapidjson.org/)
