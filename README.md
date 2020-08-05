
# Electron-Win-App-Rect

需要配合 **desktopCapturer.getSources** 返回的source.id 获取桌面应用的窗口坐标

## 修改package.json

根据需要修改 install 

"install": "node-gyp rebuild --arch=x64 --target=6.1.12 --dist-url=https://atom.io/download/electron"

--target 为指定electron版本