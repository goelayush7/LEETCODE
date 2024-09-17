# Write your MySQL query statement below

select ROUND(SUM(tiv_2016), 2) tiv_2016 from Insurance a  where a.tiv_2015 
in (
    select tiv_2015 from Insurance where 
    a.pid<>pid
)
and (a.lon,a.lat) not in (
    select lon , lat from insurance 
    where a.pid<>pid
)