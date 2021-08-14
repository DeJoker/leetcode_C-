



```note

Debugger executable '/usr/local/bin/gdb' is not signed. As a result, debugging may not work properly.

https://blog.csdn.net/github_33873969/article/details/78511733


"miDebuggerPath": "/usr/local/bin/gdb",


codesign -s gdb -cert /usr/local/bin/gdb

$ codesign -f -s gdb_cert /usr/local/bin/gdb

$ sudo codesign -f -s gdb-cert $(which gdb)
error: The specified item could not be found in the keychain.




2、仍有问题
Unable to find Mach task port for process-id 90648: (os/kern) failure (0x5).
 (please check gdb is codesigned - see taskgated(8))

echo "set startup-with-shell off" >> ~/.gdbinit


写etc下的东西需要root sudo vim 不能echo 
echo "set startup-with-shell off" >> /etc/gdbinit




3、不用自签名证书

https://blog.csdn.net/cai742925624/article/details/114642700






4、


Unable to start debugging. GDB exited unexpectedly with exit code 134 (0x86).

```


```note
1、语法检查使用cpp11
"C_Cpp.default.cppStandard": "c++14"


2、vscode mac 支持C++11 【暂时未遇到该问题】
还是点击插件，然后找到code runner
会发现右下角还有个配置的地方
配置 里 会修改一个settng.json
改了按照文件扩展来 ，不行
直接改map 采生效

{
    "workbench.colorTheme": "Visual Studio Light - C++",
    "C_Cpp.updateChannel": "Insiders",
    "window.zoomLevel": 1,
    "editor.fontSize": 11,
    "editor.suggestSelection": "first",
    "vsintellicode.modify.editor.suggestSelection": "automaticallyOverrodeDefaultValue",
    "http.proxySupport": "off",
    "code-runner.executorMapByFileExtension": {
        "code-runner.runInTerminal": true,
        "C_Cpp.default.cppStandard": "c++14",
        "code-runner.executorMap": {
            "cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt -std=c++14 && $dir$fileNameWithoutExt"
        },
        "files.associations": {
            "typeinfo": "cpp"
        },
        "window.zoomLevel": 1,
    },
    "code-runner.executorMap": {
        "cpp": "g++ $fileName -std=c++14 -o $fileNameWithoutExt.exe && ./$fileNameWithoutExt.exe"
    },
    "C_Cpp.default.cppStandard": "c++14"
}

```