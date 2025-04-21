-- 2번이상 쓰인 동물의 이름과, 쓰인 횟수 조회
-- 이름 없는 동물 집계 제외, 결과는 이름순 조회 -> ASC
SELECT NAME, COUNT(*) AS COUNT
FROM ANIMAL_INS
GROUP BY NAME
HAVING COUNT(NAME) >= 2
ORDER BY NAME ASC