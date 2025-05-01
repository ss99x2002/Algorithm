-- 동물 아이디와 이름, 중성화 여부
-- 아이디 순으로 조회
-- 중성화 되면 O, 아니면 X
SELECT ANIMAL_ID, NAME, 
CASE
    WHEN SEX_UPON_INTAKE LIKE '%Neutered%' OR SEX_UPON_INTAKE LIKE '%Spayed%' THEN 'O'
    ELSE 'X'
END as '중성화'
FROM ANIMAL_INS
ORDER BY ANIMAL_ID