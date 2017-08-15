# TGFont
[繁体中文](README.zh_TW.md)

修改 Telegram desktop Windows 版字体的简单的 hook 工具. (理论上也支持别的软件)

# 使用方法
[下载](https://github.com/ysc3839/TGFont/releases) `TGFont.dll` 并重命名为 `winmm.dll`. 然后放在 Telegram 的文件夹里.

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
            "#strikeOut": false
        }
    },
    "debug": false
}
```
`key ("SimSun")`: 要修改的字体名称.

`replace`: 要替换成的字体名称.

`size` `width` `weight` `italic` `underLine` `strikeOut`: 覆盖原始字体样式. 分别为: 字体大小 宽度 字重(粗体) 斜体 下划线 删除线. 如果不想覆盖的话请把这些项删除或者改名.

`debug`: 调试模式 (会记录 CreateFont 调用到 TGFont.log).

# Thanks
感谢宣传此项目的朋友!

[RapidJSON](http://rapidjson.org/)
