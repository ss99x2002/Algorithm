-- 보호시작일보다 입양일이 더 빠른 
-- 동물 아이디, 이름 조회하는 SQL문
-- 보호시작일이 빠른 순으로 조회
SELECT ai.animal_id, ai.name
FROM animal_ins as ai left join animal_outs as ao
on ai.animal_id = ao.animal_id
WHERE ao.datetime < ai.datetime
ORDER BY ai.datetime asc