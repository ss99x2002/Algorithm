-- 아직 입양 못 간 동물 중 가장 오래 보호소에 있던 동물 3마리
-- 동물 이름, 보호 시작일 조회
-- 결과는 보호시작일 순 조회
SELECT ai.name, ai.datetime 
FROM animal_outs as ao right join animal_ins as ai
on ai.animal_id = ao.animal_id
where ao.animal_id is null
order by ai.datetime asc
limit 3