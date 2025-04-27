-- 2번 형질이 보유하지 않으면서, 1번이나 3번 형질 보유하는 
-- 대장균의 수를 출력하는 SQL

SELECT COUNT(*) as COUNT
FROM ECOLI_DATA
WHERE ((GENOTYPE & 2) = 0) && ((GENOTYPE & (1+4)) > 0 )

-- GENOTYPE ex)15
-- GENOTYPE 15 & 2 = 
-- 1111 & 0010 
-- 2번 타입에 대해서만 1,0 비교 가능
-- =1이면 가짐, 0이면 안가짐.
-- 따라서 안가지기 위해서는 0이어야 함. 