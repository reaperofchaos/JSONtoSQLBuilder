CREATE TABLE IF NOT EXISTS `dogu` (
id INTEGER PRIMARY KEY ASC,
archaeologicalSite VARCHAR NULL,
image VARCHAR NULL,
location VARCHAR NULL,
museum VARCHAR NULL,
name VARCHAR NULL,
nickname VARCHAR NULL,
period VARCHAR NULL,
src VARCHAR NULL);

INSERT INTO dogu(archaeologicalSite, image, location, museum, name, nickname, period, src) 
VALUES 
	('Tanabatake Site', 'dogu/Tanabatake.jpg', 'Nagano', 'Togariishi Jmon Archeological Museum', 'Tanabatake', 'Jomon Venus', 'Middle Jomon', 'http://www.orjach.org/wp-content/uploads/Fig01-Tanabatake-400x444.jpg'),
	('Urushishita Site', 'dogu/Urushishita.jpg', 'Akita', '', 'Urushishita', 'Triangle-headed', 'Late Jomon', 'http://www.orjach.org/wp-content/uploads/Fig02-400x678.jpg'),
	('Chobonaino Site', 'dogu/Chobonaino.jpg', 'Hokkaido', '', 'Chobonaino', 'Hollow Dogu', 'Late Jomon', 'http://www.orjach.org/wp-content/uploads/Fig05-400x697.jpg'),
	('Mori-machi Site', 'dogu/morimachi.jpg', 'Hokkaido', '', 'Mori-machi', '', 'Late Jomon', 'http://orjach.org/module/mystery-of-the-dogu-figurine/#Fig__04___Dogu_from_Mori_machi__Hokkaido__Late_Jomon__c__1500_1000_BC_'),
	('Toyooka Site', 'dogu/Toyooka.jpg', 'Iwate', '', 'Toyooka Dogu', 'Goggle-eyed Dogu', 'Final Jomon', 'http://www.orjach.org/wp-content/uploads/cid_1e7a4b66-9a43-49da-ae4f-077da42d015b@exch_uea_ac-400x411.jpg'),
	('Kasori Site', 'dogu/kasori.jpg', 'Chiba', '', 'Kasori Dogu', '', 'Late Jomon', 'http://www.orjach.org/wp-content/uploads/Fig09-400x304.jpg'),
	('Aidani-Kumahara Site', 'dogu/Aidani-kumahara.jpg', 'Shiga', '', 'Aidani-Kumahara Dogu', '', 'Incipient Jomon', 'http://www.orjach.org/wp-content/uploads/Fig10-01-400x272.jpg'),
	('Sannai Maruyama Site', 'dogu/Sannai Maruyama.jpg', 'Aomori', 'Cultural Property Preservation Division, Aomori Prefectural Government', 'Sannai Maruyama Dogu', 'Cruciform Dogu', 'Middle Jomon', 'http://www.orjach.org/wp-content/uploads/Fig12-Sannai-400x534.jpg'),
	('Shakado Site', 'dogu/Shakado.jpg', 'Yamanashi', '', 'Shakado Dogu', '', 'Middle Jomon', 'http://www.orjach.org/wp-content/uploads/Fig11-400x418.jpg'),
	('Kazahari Site', 'dogu/Kazahari.jpg', 'Aomori', '', 'Kazahari Dogu', 'Seated Dogu', 'Late Jomon', 'http://www.orjach.org/wp-content/uploads/Fig13-400x413.jpg'),
	('Imojiya Site', 'dogu/Imojiya.jpg', 'Yamanashi', '', 'Imojiya Dogu', 'Hollow Cylindrical Dogu', 'Middle Jomon', 'http://www.orjach.org/wp-content/uploads/Fig15-400x600.jpg'),
	('Nishinomae Site', 'dogu/Funagata.jpg', 'Yamagata', 'Yamagata Prefectural Board of Education', 'Funagata Dogu', 'Standing Dogu', 'Middle Jomon', 'https://www.tnm.jp/en/exhibition/special/images/200912dogu/200912dogu07.jpg'),
	('Kamikurokoma Site', 'dogu/Kamikurokoma.jpg', 'Yamanashi', 'Tokyo National Museum', 'Kamikurokoma Dogu', '', 'Middle Jomon', 'https://www.tnm.jp/en/exhibition/special/images/200912dogu/200912dogu08.jpg'),
	('Gohara Site', 'dogu/Gohara.jpg', 'Gunma', 'Private Collection', 'Gohara Dogu', 'Heart-Shaped Dogu', 'Late Jomon', 'https://www.tnm.jp/en/exhibition/special/images/200912dogu/200912dogu09.jpg'),
	('Nakappara Site', 'dogu/Nakappara.jpg', 'Nagano', 'Chino City Board of Education, Nagano', 'Nakappara Dogu', 'Masked Dogu', 'Late Jomon', 'https://www.tnm.jp/en/exhibition/special/images/200912dogu/200912dogu10.jpg'),
	('Kamegaoka Site', 'dogu/Kamegaoka.jpg', 'Aomori', 'Tokyo National Museum', 'Kamegaoka Dogu', 'Goggle Dogu', 'Final Jomon', 'https://www.tnm.jp/en/exhibition/special/images/200912dogu/200912dogu11.jpg'),
	('Shidanai Site', 'dogu/Shidanai.jpg', 'Iwate', '', 'Shidanai Dogu', 'Dogu Head', 'Late Jomon', 'https://www.tnm.jp/en/exhibition/special/images/200912dogu/200912dogu12.jpg'),
	('Tokoshinai Site', 'dogu/Tokoshinai.jpg', 'Aomori', 'Hirosaki City Museum', 'Tokoshinai Dogu', 'Boar Dogu', 'Late Jomon', 'https://www.tnm.jp/en/exhibition/special/images/200912dogu/200912dogu13.jpg'),
	('Ebisuda Site', 'dogu/Ebisuda.jpg', 'Miyagi', '', 'Ebisuda Dogu', 'Goggle-eyed Dogu', 'Final Jomon', 'http://4.bp.blogspot.com/-Ja_UhfjU-uI/Tf--iJeimAI/AAAAAAAAB6Y/fRj4Nc-wk40/s1600/Dogu_statue.jpg'),
	('Kitakami Site', 'dogu/Kitakami.png', 'Miyagi', '', 'Kitakami Dogu', '', 'Final Jomon', 'https://classconnection.s3.amazonaws.com/594/flashcards/716594/png/screen_shot_2013-12-12_at_110341_pm-142EA201EA47D332DF4-thumb400.png');