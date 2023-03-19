run:
	cd Algorithm/Rust/study
	cargo run

clean:
	cargo fix --allow-dirty --allow-staged
	cargo fmt

upload: 
	git add .
	git commit -m "Update"
	git push