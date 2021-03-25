SELECT e1.salary
    FROM employee e1 JOIN employee e2 ON e1.salary <= e2.salary
    GROUP BY e1.salary
    HAVING 
        count(DISTINCT e2.salary) = N

SELECT salary FROM  employee
    GROUP BY salary ORDER BY salary DESC
    LIMIT N, 1


SELECT DISTINCT e.salary
      FROM employee e
      WHERE 
        (SELECT count(DISTINCT salary) 
            FROM employee WHERE salary>e.salary) = N-1


SELECT e1.salary
    FROM employee e1, employee e2 
    WHERE e1.salary <= e2.salary
    GROUP BY e1.salary
    HAVING 
        count(DISTINCT e2.salary) = N

SELECT DISTINCT salary 
    FROM 
        (SELECT 
            salary, @r:=IF(@p=salary, @r, @r+1) AS rnk,  @p:= salary 
        FROM  employee, (SELECT @r:=0, @p:=NULL)init 
        ORDER BY 
            salary DESC
        ) tmp
    WHERE rnk = N



CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    # 定义变量接收返回值
    DECLARE ans INT DEFAULT NULL;  

    # 执行查询语句，并赋值给相应变量
    SELECT 
        DISTINCT salary INTO ans
    FROM 
        (SELECT 
            salary, @r:=IF(@p=salary, @r, @r+1) AS rnk,  @p:= salary 
        FROM  
            employee, (SELECT @r:=0, @p:=NULL)init 
        ORDER BY 
            salary DESC) tmp
    WHERE rnk = N;

    # 返回查询结果，注意函数名中是 returns，而函数体中是 return
    RETURN ans;
END



SELECT DISTINCT salary INTO ans

FROM employee, (SELECT @r:=0, @p:=NULL)init 






CREATE TABLE `t_xx_device` (
`c_id` BIGINT(32) UNSIGNED NOT NULL AUTO_INCREMENT,
`c_appid` VARCHAR(32) NOT NULL,
`c_device_id` VARCHAR(128) NOT NULL,
`c_token` VARCHAR(256)  NOT NULL,
`c_deleted` TINYINT(2) NOT NULL DEFAULT 0 COMMENT '反注册',
`c_ctime` DATETIME(3) NOT NULL DEFAULT CURRENT_TIMESTAMP(3) COMMENT '创建时间',
`c_utime` DATETIME(3) NOT NULL DEFAULT CURRENT_TIMESTAMP(3) ON UPDATE CURRENT_TIMESTAMP(3) COMMENT '更新时间',
PRIMARY KEY (`c_id`),
UNIQUE KEY `udx_device` (`c_device_id`,`c_appid`)
) ENGINE=INNODB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin




select 
  $__unixEpochGroup(c_timestamp, '1m', NULL) as time, 
  cast(sum(c_value) as SIGNED) as value,
  c_obj as metric
from t_monitor_data
where c_uri IN ("ios:target", "vivo:target", "oppo:target", "huawei:target", "xiaomi:target", "ntfction:push_target")
and $__unixEpochFilter(c_timestamp)
group by $__unixEpochGroup(c_timestamp, '1m', NULL)

SELECT
  $__unixEpochGroup(c_timestamp, '1m', NULL) as time, 
  cast(max(c_cur_avg) as SIGNED) as value,
  concat('MQ任务-', SUBSTRING_INDEX(c_uri, ":", -1)) as metric
FROM t_monitor_stat
WHERE c_uri LIKE 'MQTask:%'
and $__unixEpochFilter(c_timestamp)
group by $__unixEpochGroup(c_timestamp, '1m', NULL), c_uri





