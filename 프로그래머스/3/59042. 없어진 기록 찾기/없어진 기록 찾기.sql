-- 입양을 간 기록은 있는데
-- 보호소에 들어 온 기록이 없는 동물
-- 동물 id와 이름 id 순 조회하는 sql문
-- order by 동물 id, name asc 
SELECT ANIMAL_ID, NAME
FROM ANIMAL_OUTS
WHERE animal_id NOT IN (
    select ANIMAL_ID
    from ANIMAL_INS
)
ORDER BY ANIMAL_ID, NAME