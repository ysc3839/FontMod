# TGFont
[簡體中文](README.md)

修改 Telegram desktop Windows 版字型的簡單的 hook 工具. (理論上也支援別的軟體)

# 使用方法
[下載](https://github.com/ysc3839/TGFont/releases) `TGFont.dll` 並更名為 `winmm.dll`. 然後放在 Telegram 的檔案夾裏.

使用者字型: 把字型檔案放在 `fonts` 檔案夾內, 可以直接使用, 無需安裝到系統中.

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
`key ("SimSun")`: 要修改的字型名稱.

`replace`: 要替換成的字型名稱. 繁體環境下建議改爲 `Microsoft JhengHei UI`

`size` `width` `weight` `italic` `underLine` `strikeOut` `charSet` `outPrecision` `clipPrecision` `quality` `pitchAndFamily`: 覆蓋原始字型樣式. 請參見 [MSDN 文檔](https://msdn.microsoft.com/en-us/library/dd145037). 如果不想覆蓋的話請把這些項刪除或者改名.

`debug`: 除錯模式 (會記錄 LoadUserFonts 及 CreateFont 調用到 TGFont.log).

`fixGSOFont`: 修復 GetStockObject 字型。若設為 `true` 則會使用 [SystemParametersInfo](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-systemparametersinfow#spi_getnonclientmetrics) 獲取系統字型。

> 如果只想替換中文字型，保留英文字型不變，你需要將 "key" 設為中文的 fallback 字型。這個字型在不同語言環境下可能不一樣 (比如簡體中文是 SimSun)，你需要使用 debug 模式找到對應的字型。

# Thanks
感謝宣傳此項目的朋友!

[RapidJSON](http://rapidjson.org/)
