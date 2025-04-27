-- 부모의 형질 모두 보유한 대장균의 id, 형질, 부모 형질 출력
-- id 오름차순 출력

SELECT ed.ID, ed.GENOTYPE,ed2.GENOTYPE as PARENT_GENOTYPE
FROM ECOLI_DATA as ed JOIN ECOLI_DATA as ed2 
ON(ed.parent_id = ed2.id)
WHERE (ed.GENOTYPE & ed2.GENOTYPE ) = ed2.GENOTYPE 
ORDER BY ed.ID ASC