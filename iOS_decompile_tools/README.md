# MonkeyDevInMacOS15
安装MonkeyDev可能需要的文件

最近帮同事在新电脑上安装MonkeyDev插件时遇到的问题

在新版系统和新版xcode环境下，MonkeyDev脚本会有一个路径读不到，估计是新旧版这个路径不同

好在自己这里两台电脑，专门把一台电脑停留在了10.14，因为15刚出的时候确实很多东西不兼容

也算是派上了用场，直接在10.14下的老版xcode中把报错信息中的路径和文件夹直接拷贝到新版里就ok了

路径：/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/Library/Xcode/Specifications

有人同样有需求的话自提吧，就是这个项目中这个文件夹，根据报错放进去就好

从10.14一路升上来的不会有问题，目前只发现全新的会出现。

另外，按作者wiki的自动安装脚本可能会遇到curl报错: Failed to connect to raw.githubusercontent.com port:443

如果使用代理，改hosts均无法解决问题，可以选择手动安装

手动clone项目及依赖，运行安装脚本

git clone https://github.com/AloneMonkey/MonkeyDev.git

git clone -b 3.x https://github.com/AloneMonkey/frida-ios-dump.git

sudo MonkeyDev/bin/md-install

遇到上述错误时，拷贝文件frida-ios-dump/dump.py和frida-ios-dump/dump.js，粘贴到opt/MonkeyDev/bin

之后修改安装脚本md-install，注释掉下载部分

#下载一些基础文件和模板文件

#downloadGithubTarball "https://codeload.github.com/AloneMonkey/MonkeyDev/tar.gz/$branch" "$MonkeyDevPath" "MonkeyDev base"

#downloadGithubTarball "https://codeload.github.com/AloneMonkey/MonkeyDev-Xcode-Templates/tar.gz/$branch" "$MonkeyDevPath/templates" "Xcode templates"

##下载frida-ios-dump

#echo "Downloading frida-ios-dump from Github..."

#downloadFile "https://raw.githubusercontent.com/AloneMonkey/frida-ios-dump/3.x/dump.py" "$MonkeyDevPath/bin/dump.py"

#downloadFile "https://raw.githubusercontent.com/AloneMonkey/frida-ios-dump/3.x/dump.js" "$MonkeyDevPath/bin/dump.js"

保存后再次运行脚本，安装成功。

