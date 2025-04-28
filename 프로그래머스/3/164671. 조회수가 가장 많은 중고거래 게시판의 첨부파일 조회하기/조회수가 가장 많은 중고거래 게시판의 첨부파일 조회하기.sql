-- 조회수가 가장 높은 중고거래 게시물에 대한
-- 첨부파일 경로 조회 
-- filE ID 기준 내림차순
-- 게시물 ID 기준 디렉토리 분리, 파일이름은 파일ID,파일이름,파일확장자 로 구성되어 출력 
-- CONCAT 나열로 붙이기
SELECT CONCAT('/home/grep/src/',uf.board_id,'/', uf.file_id, uf.file_name, uf.file_ext) as FILE_PATH
FROM USED_GOODS_BOARD as ub JOIN USED_GOODS_FILE as uf
ON ub.board_id = uf.board_id
WHERE views = (
    SELECT MAX(VIEWS)
    FROM USED_GOODS_BOARD
)
ORDER BY FILE_PATH DESC