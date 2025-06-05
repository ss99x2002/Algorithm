-- 이름에 el들어가는 개의 아이디와 이름 조회 SQL
-- 결과를 이름순으로 조회 
SELECT ANIMAL_ID, NAME 
FROM ANIMAL_INS
WHERE NAME LIKE '%el%' AND ANIMAL_TYPE = 'Dog'
ORDER BY NAME 