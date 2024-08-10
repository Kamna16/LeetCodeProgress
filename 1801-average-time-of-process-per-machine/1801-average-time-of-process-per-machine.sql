# Write your MySQL query statement below
SELECT a1.machine_id , round(avg(a2.timestamp-a1.timestamp),3)  as processing_time
FROM activity a1
JOIN activity a2
ON a1.machine_id  = a2.machine_id 
AND a1.process_id = a2.process_id
AND a1.timestamp <a2.timestamp
group by a1.machine_id