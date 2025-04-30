-- 거래 게시물 3건이상 등록한 사용자의
-- id,닉네임, 전체주소, 전화번호 조회
-- 전화번호는 - 삽입해서 출력
SELECT USER_ID
        ,NICKNAME
        ,CONCAT(CITY,' ',STREET_ADDRESS1,' ', STREET_ADDRESS2) AS 전체주소
        ,CONCAT(SUBSTRING(TLNO, 1, 3), '-', -- 앞자리 (010)
              SUBSTRING(TLNO, 4, 4), '-',   -- 가운데자리 (1234)
              SUBSTRING(TLNO, 8, 4)) AS 전화번호 -- 뒷자리 (5678)
FROM USED_GOODS_USER 
WHERE USER_ID IN (SELECT WRITER_ID
                   FROM USED_GOODS_BOARD
                   GROUP BY WRITER_ID
                   HAVING COUNT(WRITER_ID) >=3 )
ORDER BY USER_ID DESC