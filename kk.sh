if [[ "${line}" = "# Owner" ]];then
    continue
elif [[ "${line}" = "" ]]|| [[ "${line}" = "#"* ]];then
    break
else
    owner+="${line},"
fi

for i in `seq 1 100`; do ifconfig eth2 | grep RX ; sleep 1; done

{
        "method": "synchronizeStudentJoinMsg",
        "params": "{\"courseId\":\"581529754817634304\",\"courseName\":\"1.2.2合规检查\",\"courseClassId\":\"581529755250491392\",\"courseClassName\":\"默认班级\",\"teacherName\":\"婉君一八六的测试环境账号\"}"
      }




