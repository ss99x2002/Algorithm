-- 2022-10월 작성된 제목, 게시글 id, 댓글 작성자 id, 댓글 내용, 댓글 작성일 조회
SELECT ub.title as TITLE, 
ub.board_id as BOARD_ID, 
ur.reply_id as REPLY_ID, 
ur.writer_id as WRITER_ID, 
ur.contents as CONTENTS, 
DATE_FORMAT(ur.created_date, '%Y-%m-%d') as CREATED_DATE
FROM USED_GOODS_BOARD as ub JOIN USED_GOODS_REPLY as ur
ON ub.board_id = ur.board_id
WHERE DATE_FORMAT(ub.created_date, '%Y-%m')='2022-10'
ORDER BY DATE_FORMAT(ur.created_date, '%Y-%m-%d'), TITLE ASC