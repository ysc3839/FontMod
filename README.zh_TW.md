# FontMod
[English](README.md) [简体中文](README.zh_CN.md) **繁体中文**

修改 Win32 程式字型的簡單的 hook 工具。可用於一些基於 GDI 或者 Qt 的程式。

> 經測試可用於 [Telegram Desktop](https://desktop.telegram.org/)、[Kleopatra (Gpg4Win)](https://www.gpg4win.org/) 和 [Mendeley Desktop](https://www.mendeley.com/download-desktop/)。

# 使用方法
[下載](https://github.com/ysc3839/FontMod/releases) `FontMod{32,64}.dll` 並更名為下列之一： 
`dinput8.dll`, `dinput.dll`, `dsound.dll`, `d3d9.dll`, `d3d11.dll`, `ddraw.dll`, `winmm.dll`, `version.dll`, `d3d8.dll` (`d3d8.dll` 僅支援 32 位元)。  
然後放在程式 exe 所在的檔案夾裏。  
使用者字型: 把字型檔案放在 `fonts` 檔案夾內，可以直接使用，無需安裝到系統中。

# 組態檔案
初次運行時會建立 `FontMod.yaml`。組態檔案使用 UTF-8 編碼。支援 UTF-8 BOM。
```yaml
style: &style
# Remove '#' to override font style
#  size: 0
#  width: 0
#  weight: 0
#  italic: false
#  underLine: false
#  strikeOut: false
#  charSet: 0
#  outPrecision: 0
#  clipPrecision: 0
#  quality: 0
#  pitchAndFamily: 0

fonts:
  SimSun: &zh-cn-font # Chinese (Simplified) fallback font
    replace: Microsoft YaHei
    <<: *style
  PMingLiU: # Chinese (Traditional) fallback font
    replace: Microsoft JhengHei UI
    <<: *style
  MS UI Gothic: # Japanese fallback font
    replace: Yu Gothic UI
    <<: *style
  Gulim: # Korean fallback font
    replace: 맑은 고딕
    <<: *style

fixGSOFont: true # true is to use system UI font
#fixGSOFont: *zh-cn-font # Or replace with user defined font
debug: false
```
* fonts
  * `key ("SimSun")`: 要修改的字型名稱。
  * `replace` / `name`: 要替換成的字型名稱。
  * `size` `width` `weight` `italic` `underLine` `strikeOut` `charSet` `outPrecision` `clipPrecision` `quality` `pitchAndFamily`: 覆蓋原始字型樣式。請參見 [MSDN 文檔](https://docs.microsoft.com/en-us/windows/desktop/api/wingdi/ns-wingdi-logfontw)。如果不想覆蓋的話請把這些項刪除。

* fixGSOFont
替換 [GetStockObject](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-getsyscolorbrush) 字型，選項與前面的 `fonts` 相同。若設為 `true` 則會使用 [SystemParametersInfo](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-systemparametersinfow#spi_getnonclientmetrics) 獲取系統字型。

* debug
除錯模式 (會記錄相關訊息到 FontMod.log)。

> YAML 支援 `錨點(&)` 和 `參照(*)` (請參見 [維基百科](https://zh.wikipedia.org/wiki/YAML#%E8%B3%87%E6%96%99%E5%90%88%E4%BD%B5%E5%92%8C%E5%8F%83%E8%80%83))，此工具還支援 YAML 標準中非強制的[鍵值合併](https://yaml.org/type/merge.html) (Merge Key) 功能。你可以像上面的組態檔案那樣重復使用數據，而不需要像 JSON 那樣把數據複製多份。

> 如果只想替換 CJK 字型，保留英文字型不變，你需要將 "key" 設為 CJK 的 fallback 字型。這個字型在不同語言環境下可能不一樣 (比如簡體中文是 SimSun)，你可以使用 debug 模式找到對應的字型。
