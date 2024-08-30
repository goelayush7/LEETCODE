# Write your MySQL query statement below
select A1.machine_id , abs(round(avg(A1.timestamp-A2.timestamp),3)) as processing_time from 
Activity A1 join Activity A2
on A1.machine_id=A2.machine_id and A1.process_id=A2.process_id
and A1.activity_type='start' and A2.activity_type='end'
group by A1.machine_id