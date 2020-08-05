
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


## 使用

**注意：**

source.id 返回的格式为  window:18238:0
调用时，需要传入 其中的 18238 并且为 Number类型

```
    const sourceId = source.id.split(':')[1];
    const appId = parseInt(appId);
    const rect = Eagle.getWindowRect(appId);
    console.log(rect);
```


```
const Eagle = require('electron-win-app-rect');

// In the renderer process.
const { desktopCapturer } = require('electron')

desktopCapturer.getSources({ types: ['window', 'screen'] }).then(async sources => {
  for (const source of sources) {
    if (source.name === 'Electron') {
      try {
        const stream = await navigator.mediaDevices.getUserMedia({
          audio: false,
          video: {
            mandatory: {
              chromeMediaSource: 'desktop',
              chromeMediaSourceId: source.id,
              minWidth: 1280,
              maxWidth: 1280,
              minHeight: 720,
              maxHeight: 720
            }
          }
        })
        const sourceId = source.id.split(':')[1];
        const appId = parseInt(appId);
        const rect = Eagle.getWindowRect(appId);
        handleStream(stream)
      } catch (e) {
        handleError(e)
      }
      return
    }
  }
})

function handleStream (stream) {
  const video = document.querySelector('video')
  video.srcObject = stream
  video.onloadedmetadata = (e) => video.play()
}

function handleError (e) {
  console.log(e)
}

```

