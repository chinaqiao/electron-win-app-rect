
# Electron-Win-App-Rect

需要配合 **desktopCapturer.getSources** 返回的source.id 获取桌面应用的窗口坐标

## 安装

根据需要修改 install 

```
    npm i -s electron-win-app-rect
```

## Electron 版本对应

如果使用 **NODE_MODULE_VERSION** 版本不一致，则需要进入目录手动编译，同时指定electron版本

> --target 为指定electron版本

```
     "node-gyp rebuild --arch=x64 --target=6.1.12 --dist-url=https://atom.io/download/electron"
```
如果需要修改main.cc代码，修改完成后，在执行build


