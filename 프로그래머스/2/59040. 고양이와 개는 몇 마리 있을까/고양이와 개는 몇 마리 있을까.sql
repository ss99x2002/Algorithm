-- 보호소에 들어온 동물 중
-- 고양이와 개가 몇마리인지 조회
-- 고양이를 개보다 먼저 조회
SELECT ANIMAL_TYPE, count(*) as count
FROM ANIMAL_INS
WHERE ANIMAL_TYPE in ('Cat','Dog')
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE