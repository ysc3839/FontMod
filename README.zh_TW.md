# TGFont
[簡體中文](README.md)

修改 Telegram desktop Windows 版字型的簡單的 hook 工具. (理論上也支援別的軟體)

# 使用方法
[下載](https://github.com/ysc3839/TGFont/releases) `TGFont.dll` 並更名為 `winmm.dll`. 然後放在 Telegram 的檔案夾裏.

# 組態檔案
初次運行時會建立 `TGFont.json`. 組態檔案使用 UTF-8 編碼. 支援 UTF-8 BOM.
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
`key ("SimSun")`: 要修改的字型名稱.

`replace`: 要替換成的字型名稱. 繁體環境下建議改爲 `Microsoft JhengHei UI`

`size` `width` `weight` `italic` `underLine` `strikeOut`: 覆蓋原始字型樣式. 分別為: 字型大小 寬度 字重(粗體) 斜體 下劃線 刪除線. 如果不想覆蓋的話請把這些項刪除或者改名.

`debug`: 除錯模式 (會記錄 CreateFont 調用到 TGFont.log).

# Thanks
感謝宣傳此項目的朋友!

[RapidJSON](http://rapidjson.org/)
