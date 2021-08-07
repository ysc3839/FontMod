# FontMod
**English** [简体中文](README.zh_CN.md) [繁体中文](README.zh_TW.md)

Simple hook tool to change Win32 program font. Works with some GDI/GDI+ or Qt based program.

> Proven workable on [Telegram Desktop](https://desktop.telegram.org/), [Kleopatra (Gpg4Win)](https://www.gpg4win.org/) and [Mendeley Desktop](https://www.mendeley.com/download-desktop/).

# Usage
[Download](https://github.com/ysc3839/FontMod/releases) `FontMod{32,64,ARM,ARM64}.dll` and rename to one of following:  
`dinput8.dll`, `dinput.dll`, `dsound.dll`, `d3d9.dll`, `d3d11.dll`, `ddraw.dll`, `winmm.dll`, `version.dll`, `d3d8.dll` (`d3d8.dll` is 32bit only).  
Then put in the folder of program exe.  
User font: Put fonts in `fonts` folder to use them directly, don't need to install to system.

# Config file
Will create `FontMod.yaml` on first run. Config file uses UTF-8 encoding. Support UTF-8 BOM.
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

#fixGSOFont: true # true is to use system UI font
#fixGSOFont: *zh-cn-font # Or replace with user defined font

#gdiplus:
#  SimSun:
#    replace: Microsoft YaHei
#  Microsoft YaHei:
#    size: 72.0
#    style: regular
##    style: 0
#    unit: point
##    unit: 3

#gdipGFFSansSerif: Calibri
#gdipGFFSerif: Times New Roman
#gdipGFFMonospace: Consolas

debug: false
```
* fonts
  * `key ("SimSun")`: Font name to modify.
  * `replace` / `name`: Font name to replace.
  * `size` `width` `weight` `italic` `underLine` `strikeOut` `charSet` `outPrecision` `clipPrecision` `quality` `pitchAndFamily`: Override original font style. Please refer to [MSDN docs](https://docs.microsoft.com/en-us/windows/desktop/api/wingdi/ns-wingdi-logfontw). If you don't want to override, delete these items.

* fixGSOFont
Replace [GetStockObject](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-getsyscolorbrush) font, the options is same as `fonts` above. If set to `true` will use [SystemParametersInfo](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-systemparametersinfow#spi_getnonclientmetrics) to get system font.

* gdiplus
Replace GDI+ font. Due to limitation of GDI+, you can only replace a font with another (`SimSun` -> `Microsoft YaHei`), or change the style of a font.
  * `key ("SimSun")`: Font name to modify.
  * `replace` / `name`: Font name to replace.
  * `size`: Font size.
  * `style`: Font style. Possible values are: `regular` `bold` `italic` `boldItalic` `underline` `strikeout`. Or you can just write integer value of [FontStyle enumeration](https://docs.microsoft.com/en-us/windows/win32/api/gdiplusenums/ne-gdiplusenums-fontstyle).
  * `unit`: Unit of size. Possible values are: `world` `display` `pixel` `point` `inch` `document` `millimeter`. Or you can just write integer value of [Unit enumeration](https://docs.microsoft.com/en-us/windows/win32/api/gdiplusenums/ne-gdiplusenums-unit).

* gdipGFFSansSerif, gdipGFFSerif, gdipGFFMonospace
Replace GDI+ generic font family. (https://docs.microsoft.com/en-us/windows/win32/gdiplus/-gdiplus-fontfamily-flat)

* debug
Debug mode (Will log information to FontMod.log).

> YAML supports `anchors(&)` and `references (*)` (Please refer to [Wikipedia](https://en.wikipedia.org/wiki/YAML#Advanced_components)), this tool also supports not mandatory [Merge Key](https://yaml.org/type/merge.html) function in YAML spec. You can reuse data like config file above, and don't need to copy multiple times like JSON.

> If you want replace only CJK fonts and keep English font, you need to set `key` to CJK fallback font. This font may be different in different language environments. (For example in Chinese simplified environment is SimSun), you can use debug mode to find corresponding font.
