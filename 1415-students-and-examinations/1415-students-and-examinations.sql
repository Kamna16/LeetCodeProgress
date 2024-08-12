# Write your MySQL query statement below
SELECT s.student_id, s.student_name, sub.subject_name,count(e.subject_name) as attended_exams
FROM Students s
CROSS JOIN Subjects sub
LEFT JOIN Examinations e
ON s.student_id = e.student_id
AND e.subject_name = sub.subject_name 
GROUP BY s.student_id, s.student_name, sub.subject_name
ORDER BY s.student_id, s.student_name;