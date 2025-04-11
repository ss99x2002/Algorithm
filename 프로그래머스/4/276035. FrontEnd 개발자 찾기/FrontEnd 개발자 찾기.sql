-- 개발자 테이블에서 frontend 스킬 
-- 개발자 id, 이메일, 이름, 성 조회 
-- id기준 오름차순 정렬
SELECT 
    ID,
    EMAIL,
    FIRST_NAME,
    LAST_NAME
FROM
    DEVELOPERS
WHERE
    SKILL_CODE & (
        SELECT SUM(CODE)
        FROM SKILLCODES
        WHERE CATEGORY = 'Front End'
    ) > 0
ORDER BY ID ASC; -- 비트연산자 활용