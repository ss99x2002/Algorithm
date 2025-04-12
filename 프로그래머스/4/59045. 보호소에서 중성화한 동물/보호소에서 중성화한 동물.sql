-- 보호소에 들어올 때는 중성화 안되어있지만
-- 보호소 나갈 당시에는 중성화된 아동물 중
-- 아이디, 생물종, 이름 조회
-- 아이디 순으로 조회 ASC 
-- sex-upon-outcome -> 중성화 여부, spayed 
SELECT animal_id, animal_type, name
FROM animal_ins
WHERE animal_id in (
    select animal_id
    from animal_outs
    where sex_upon_outcome in ('Spayed Female','Neutered Male')
) AND sex_upon_intake in ('Intact Male', 'Intact Female')
ORDER BY animal_id asc