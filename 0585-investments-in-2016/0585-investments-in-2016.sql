# Write your MySQL query statement below
select round(sum(tiv_2016),2) as tiv_2016 from Insurance i where
((i.lat,i.lon) not in 
    (select lat, lon from Insurance i2 where i2.pid <> i.pid) 
and 
i.tiv_2015 in 
    (select tiv_2015 from Insurance i2 where i2.pid <> i.pid));