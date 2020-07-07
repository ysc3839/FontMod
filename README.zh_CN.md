# FontMod
[English](README.md) **简体中文** [繁体中文](README.zh_TW.md)

修改 Win32 程序字体的简单的 hook 工具。可用于一些基于 GDI 或者 Qt 的程序。

> 经测试可用于 [Telegram Desktop](https://desktop.telegram.org/)、[Kleopatra (Gpg4Win)](https://www.gpg4win.org/) 和 [Mendeley Desktop](https://www.mendeley.com/download-desktop/)。

# 使用方法
[下载](https://github.com/ysc3839/FontMod/releases) `FontMod{32,64}.dll` 并重命名为下列之一：  
`dinput8.dll`, `dinput.dll`, `dsound.dll`, `d3d9.dll`, `d3d11.dll`, `ddraw.dll`, `winmm.dll`, `version.dll`, `d3d8.dll` (`d3d8.dll` 仅支持 32 位)。  
然后放在程序 exe 所在的文件夹里。  
用户字体：把字体文件放在 `fonts` 文件夹内，可以直接使用，无需安装到系统中。

# 配置文件
初次运行时会创建 `FontMod.yaml`。配置文件使用 UTF-8 编码。支持 UTF-8 BOM。
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
  * `key ("SimSun")`: 要修改的字体名称。
  * `replace` / `name`: 要替换成的字体名称。
  * `size` `width` `weight` `italic` `underLine` `strikeOut` `charSet` `outPrecision` `clipPrecision` `quality` `pitchAndFamily`: 覆盖原始字体样式。请参见 [MSDN 文档](https://docs.microsoft.com/en-us/windows/desktop/api/wingdi/ns-wingdi-logfontw)。如果不想覆盖的话请把这些项删除。

* fixGSOFont
替换 [GetStockObject](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-getsyscolorbrush) 字体，选项与前面的 `fonts` 相同。若设为 `true` 则会使用 [SystemParametersInfo](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-systemparametersinfow#spi_getnonclientmetrics) 获取系统字体。

* debug
调试模式 (会记录相关信息到 FontMod.log)。

> YAML 支持 `锚点(&)` 和 `引用(*)` (请参见 [维基百科](https://zh.wikipedia.org/wiki/YAML#%E8%B3%87%E6%96%99%E5%90%88%E4%BD%B5%E5%92%8C%E5%8F%83%E8%80%83))，此工具还支持 YAML 标准中非强制的[键值合并](https://yaml.org/type/merge.html) (Merge Key) 功能。你可以像上面的配置文件那样重复使用数据，而不需要像 JSON 那样把数据复制多份。

> 如果只想替换 CJK 字体，保留英文字体不变，你需要将 `key` 设为 CJK 的 fallback 字体。这个字体在不同语言环境下可能不一样 (比如简体中文是 SimSun)，你可以使用 debug 模式找到对应的字体。
