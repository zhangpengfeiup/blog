- !$
!$ 是一个特殊的环境变量，它代表了上一个命令的最后一个字符串。

- ps -ef | grep 关键字 | awk '{print $2}' | xargs kill -9