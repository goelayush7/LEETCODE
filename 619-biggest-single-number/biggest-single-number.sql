select (
    select num from Mynumbers group by num having count(num)=1 order by num desc limit 1
) as num