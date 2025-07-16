# Write your MySQL query statement below
-- select U.name from Users U join MovieRating m on U.user_id = m.user_id 
-- group by U.name 

(Select u.name as results from Users u left join MovieRating m on u.user_id = m.user_id 
group by u.name 
order by count(m.user_id) desc ,u.name
limit 1)
union all 
(Select M.title as results from Movies M left join MovieRating m1 on M.movie_id = m1.movie_id
where created_at like "2020-02%"
group by M.title 
order by avg(m1.rating) desc , M.title 
limit 1)