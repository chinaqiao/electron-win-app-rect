// hello.js
const addon = require('./build/Release/addon');
exports.Eagle = {
    getWindowRect: addon.getWindowRect
}
// const hwnd = sourceId.toString(16);
console.log("hwnd : " + sourceId);
const rect = addon.getWindowRect(sourceId);
console.log(" this JS Object:");
console.table(rect);